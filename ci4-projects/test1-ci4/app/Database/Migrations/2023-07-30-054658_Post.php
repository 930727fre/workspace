<?php

namespace App\Database\Migrations;

use CodeIgniter\Database\Migration;

class Post extends Migration
{
    public function up()
    {
        $this->forge->addField([
            'id'=>[
                'type'=>'INT',
                'constraint'=>5,
                'unsigned'=>True,
                'auto_increment'=>True
            ],
            'title'=>[
                'type'=>'VARCHAR',
                'constraint'=>'100',
                'null'=>True
            ],
            'content'=>[
                'type'=>'VARCHAR',
                'constraint'=>'200',
                'null'=>True
            ],
        ]);
        $this->forge->addKey('id',True);
        $this->forge->createTable('posts');
    }

    public function down()
    {
        $this->forge->dropTable('posts');
    }
}
