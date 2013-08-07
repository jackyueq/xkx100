// changxiang.c

inherit NPC;

void create()
{
	set_name( "����", ({"chang xiang", "chang", "changxiang"}) );
	set( "title", "����Ժ��ū" );
	set( "gender", "����" );
	set( "age", 33 );
	set( "str", 26 );
	set( "dex", 25 );	 
	set( "per", 26 );
	set( "attribute", "heroism" );
	set( "long", @LONG
һ���ߴ����͵ĺ��ӣ����Ƶ�һ������һ�ԡ������������Ǹ�Ц��������
�ˣ���֪Ϊ��Ҫ�ڴ˸���Ȳ��¡�
LONG
	);
	set( "max_qi", 500 );
	set( "max_jing", 500 );
	set( "attitude", "heroism" );
	set( "combat_exp", 50000 );
	set("inquiry", ([
		"½����" : "��Ҫ���ң����ǿ��ŵġ�\n",
	]));
	set("chat_chance", 3);
	set("chat_msg", ({
		"�������С���Ŷ��գ��Լ����˼��������ϧû���ܲ��У�\n",
		"�������С���ò˫�����ɺ�����³���ܺ���ͬ��(enjoy)���ϣ�\n",
	}) );
	set_skill("parry", 80);
	set_skill("blade", 80);
	set_skill("dodge", 80);
	set_skill("wuhu-duanmendao", 80);
	map_skill("blade", "wuhu-duanmendao");
	map_skill("parry", "wuhu-duanmendao");
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/male-cloth")->wear();
}

int accept_object(object me, object ob)
{
	int val, money;
	val = ob->value();
	money = ( 8 + 2 * me->query("lu_sing") ) * 1000;
	if ( val >= money )
	{
		write("���������˵�ͷ��ʾ����������ˡ�\n");
		me->delete("lu_sing");
		return 1;
	}
	if ( val > 0 )
	{
		command( "look " + me->query("id") );
		write("�������ޱ����˵�����Ҹ��߹���Ҫ������Ǯ�ġ�\n");
	}
	return 0;
}


