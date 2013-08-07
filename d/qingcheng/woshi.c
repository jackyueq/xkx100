// woshi.c

inherit ROOM;
int do_open(string arg);

void create()
{
	set("short", "����");
	set("long", @LONG
��������׺������ҡ���׺���Ȼ�ǵ��ҵ��ӣ���Ҳ������Լ����
����Ȣ�����䣬��һ��������ü���С檡������а���һ���ľ�����
����һ�ߺ��ɴ��¹񣬹񶥸��ż�ֻţƤ�����ӣ�ǽ������һ���е��
�ɵ���ױ̨ (tai)������(window)����һ�Ż���ľ������
LONG
	);
	set("key", 1);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"garden",
	]));
        set("item_desc", ([
		"window" : "������������ĵ�����ˡ�\n",
		"tai"    : "һ�ź�������ߵİ뿪����ױ̨��\n",
        ]));
	set("objects", ([
		__DIR__"npc/yuwife" : 1,
	])  ) ;

	set("coor/x", -8070);
	set("coor/y", -820);
	set("coor/z", 90);
	setup();
}
void init()
{
        add_action("do_open", "open");
        add_action("do_open", "kai");
}

int do_open(string arg)
{
	object key, me=this_player();

        if( !arg || arg!="tai" ) return 0;

        if( arg=="tai" )
	{
		if ((me->query("family/master_id") !="yu canghai") &&
			objectp(present("yu wife", environment(me))))
		{
			return notify_fail(
"��С�Ǻȵ�����λ" + RANK_D->query_respect(me) + "���㲻����㷭�˼Ҷ�����\n");
			return 1;
		}
		if (query("key"))
		{
			message_vision(
"$N����Ĵ���ױ̨���룬����������һ֧��Կ�ס�\n", me);
			key = new(__DIR__"obj/key2");
			key->move(__FILE__);
			set("key", 0);
			return 1;
		}
		message_vision(
"$N������������룬��������ɶ��û��...��\n", me);
		return 1;
	}
	return 0;
}