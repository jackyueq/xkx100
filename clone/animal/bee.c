// bee.c
// Last Modified by winder on Aug. 1 2002

inherit NPC;

void create()
{
	set_name("�۷�", ({"bee"}) );
	set("race", "����");
	set("subrace", "�ɳ�");
	set("age", 5);
	set("long", "����һֻ�۷䣬��æ�Ų��ۡ�\n");
	
	set("str", 40);
	set("dex", 50);

	set_temp("apply/attack", 33);
	set_temp("apply/armor", 5);
 	
	set("chat_chance", 2);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"�۷������˷ɹ���������ͷ��ת��һȦ���ַ����ˡ�\n",
		"�۷�ɵ�·�ߵ�һ�����޵�Ұ���ϣ�ææµµ�ز����ۡ�\n",
	 }) );

	setup();
}

