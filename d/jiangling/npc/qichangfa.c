//Edited by fandog, 02/13/2000
#include <ansi.h>;
inherit NPC;

void create ()
{
	set_name("�ݳ���", ({"qi changfa","qi"}));
	set("nickname", HIB"�����Ὥ"NOR);
	set("long", "һ����ͷ��������ҧ��һ���̶̵ĺ��̹ܡ�����ͷ�׷���������
�ƣ���������⾼Ȼ������������\n");
	set("gender", "����");
	set("age", 48);
	set("combat_exp", 1000000);
	set("str", 25);
	set("int", 28);
	set("dex", 23);
	set("con", 18);
	set("per", 18);
	set("kar", 26);
  
	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("sword", 120);
	set_skill("parry", 120);
	set_skill("yanfly", 120);
	set_skill("tangshi-jian", 120);
	map_skill("dodge", "yanfly");
	map_skill("parry", "tangshi-jian");
	map_skill("sword", "tangshi-jian");
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
}


