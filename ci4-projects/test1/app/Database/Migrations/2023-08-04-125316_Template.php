<?php

namespace App\Database\Migrations;

use CodeIgniter\Database\Migration;

class Template extends Migration
{
    public function up()
    {
        $this->forge->addField(
            [   
                'id'=>[
                    'type'=>'INT',
                    'constraint'=>1000,
                    'unsigned'=>True,
                    'auto_increment'=>True
                ],
                'fullname'=>[
                    'type'=>'VARCHAR',
                    'constraint'=>'50'
                ],
                'username'=>[
                    'type'=>'VARCHAR',
                    'constraint'=>'50'
                ],
                'password'=>[
                    'type'=>'VARCHAR',
                    'constraint'=>'50'
                ],

            ]
        );
        $this->forge->addKey('id',True);
        $this->forge->createTable('studentIdentity');
    }

    public function down()
    {
        $this->forge->dropTable('studentIdentity');
    }

}
