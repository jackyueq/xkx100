//Edited by fandog, 02/13/2000

inherit NPC;

void create ()
{
	set_name("��������", ({"jiao shu", "teacher"}));
	set("long", "��ҡͷ���Եģ�����һ��ֽ��һֻī�У�һ֦�ʣ�����д��ʲô��\n");
	set("gender", "����");
	set("age", 24);
	set("combat_exp", 1000);
	set("str", 24);
	set("int", 15);
	set("dex", 18);
	set("con", 22);
	set("per", 20);
	set("chat_msg", ({
	"���������з����ۣ���ϸ�����ų�ǽ����ʯ����д����Ŀ�֡�\n",
	"������������һ��ֽ��һֻī�У�һ֦�ʣ�ҡͷ���Եģ�����ǽ���Ǽ����ֳ�����������\n",
	"����������������������Ϸ���ô�������ô������˲�����֮Ҳ����\n",
	(: random_move :)
	}) );

  
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}


