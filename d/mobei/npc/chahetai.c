// chahetai.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("���̨",({"cha hetai","cha","hetai"}));
	set("gender","����");
	set("long","��ľ��Ķ����ӣ����Դ�³���������¶���촽�⣡\n");
	set("mingwang",-15000);
	set("combat_exp", 200000);
	set("age",34);
	set("qi",1000);
	set("max_qi",1000);
	set("food",250);
	set("water",250);
	set("neili",800);
	set("max_neili",800);
	set("chat_chance",5);
	set("chat_msg",({
		"���ܿ���˳��������С�ӣ��ϸ������ԡ�\n",
		"������ɵС�Ӿ�Ȼ������ϲ������������Ҫ����ɱ�ˡ�\n",
	}));
	set_skill("dodge", 60);
	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("unarmed", 60);
	set_skill("spear", 60);

	setup();
	add_money("silver",20);
	carry_object("/clone/armor/jinjia")->wear();
	carry_object("/clone/weapon/spear/yinqiang")->wield();
}

