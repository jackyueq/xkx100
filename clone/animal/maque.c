// maque.c ��ȸ
// Last Modified by winder on Aug. 1 2002

inherit NPC;

void create()
{
	set_name("��ȸ", ({ "ma que", "que", "bird" }) );
	set("race", "����");
	set("age", 3);
	set("long", "һֻߴߴ������������ȥ��С��ȸ��\n");
	set("attitude", "peaceful");
	
	set("combat_exp", 100);

	set("chat_chance", 10);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"С��ȸߴߴ�����Ļ����ţ�����ͷ���Ϸ�����ȥ��\n",
		"С��ȸ����ͣ��ǽͷ�������������ң�æµ����ʳ�ԡ�\n",
	}) );
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"С��ȸߴߴߴ��ŭ���ţ�ȫ�����ë������������\n",
	}) );
		
	setup();
}
