//Edited by fandog, 02/13/2000

inherit NPC;
string ask_me();

void create ()
{
	object weapon;
	set_name("����", ({"di yun","di"}));
	set("long", "��������ڣ�ȧ��΢�ߣ����ִ�ţ������������³�����ׯ�ں��ӡ�\n");
	set("gender", "����");
	set("age", 24);
	set("combat_exp", 1500000);
	set("str", 24);
	set("int", 15);
	set("dex", 18);
	set("con", 22);
	set("per", 28);
  
	set_skill("force", 200);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("blade", 200);
	set_skill("yanfly", 200);
	set_skill("shenzhao-jing", 300);
	set_skill("xue-dao", 200);
	map_skill("force", "shenzhao-jing");
	map_skill("blade", "xue-dao");
	map_skill("parry", "xue-dao");
	map_skill("unarmed", "shenzhao-jing");
	map_skill("dodge", "yanfly");
	set("inquiry", ([
		"ˮ��" : (: ask_me :),
	]));
	set("wucan_count", 1);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	if (clonep())
	{
		weapon = new( WEAPON_DIR"treasure/xblade" );	
		if ( weapon->violate_unique() )
		{
			destruct( weapon );
			weapon = new( "/clone/weapon/gangdao" );
		}
		weapon->move(this_object());
		weapon->wield();
	}
} 

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (query("wucan_count") < 1)
		return "ˮ�Ϲ������ѩ������ң�";

	add("wucan_count", -1);
	this_player()->set_temp("marks/wucan", 1);
	return "ˮ�Ϲ������ѩ������ң�����ʲô�����Ӹ���ô��";
}
int accept_object(object who, object ob)
{
	object obj;
	if (ob->query("id") != "da chang")
		return notify_fail("�����ⶫ����ʲô�ã�");
	message_vision("����Ц��˵������лл�㣡��λ" + RANK_D->query_respect(ob) +"���������ˡ���\n", who);
	if (!who->query_temp("marks/wucan"))
	{
		return 1;
	}
	obj = new(ARMOR_DIR"treasure/wucanyi");
	this_player()->delete_temp("marks/wucan");
	if ( obj->violate_unique() || uptime() < 300)
	{
		destruct( obj );
		return 1;
	}
	message_vision("���ƶ�$N˵����������ڲ���Ҳ������ʲô�������ı�����ɣ������ƴӻ����ͳ�һ�Ų����۵Ķ������ݵ�$N�����ϡ�\n", who);
	obj->move(this_player());
	return 1;
}
