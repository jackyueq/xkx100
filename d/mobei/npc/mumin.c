// mumin.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("�ɹ�����",({"mu min"}));
	set("gender","����");
	set("long","��ľ�沿�������ˡ�\n");
	set("combat_exp",600);
	
	set("age",54);
	set("qi",600);
	set("max_qi",600);
	set("food",250);
	set("water",250);
	setup();
	add_money("silver",3);
	carry_object("/clone/armor/shoupi")->wear();
}
