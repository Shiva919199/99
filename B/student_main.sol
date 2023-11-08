// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract SimpleBank {

    mapping(address => uint) private balances;
    address public owner;
    event LogDepositMade(address indexed accountAddress, uint amount);

    constructor() {
        owner = msg.sender;
    }

    function enroll() public returns (uint) {
        address user = msg.sender;
        balances[user] = 1000;
        return balances[user];
    }

    function deposit() public payable returns (uint) {
        address user = msg.sender;
        balances[user] += msg.value;
        emit LogDepositMade(user, msg.value);
        return balances[user];
    }

    function withdraw(uint withdrawAmount) public returns (uint remainingBal) {
        address payable user = payable(msg.sender);

        require(balances[user] >= withdrawAmount, "Insufficient balance");
        
        balances[user] -= withdrawAmount;
        (bool success, ) = user.call{value: withdrawAmount}("");
        require(success, "Transfer failed");
        return balances[user];
    }


    function balance() public view returns (uint) {
        address user = msg.sender;
        return balances[user];
    }

    receive() external payable {
        revert("Invalid transaction");
    }
}
