//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
������ɽ��һ����ɽ��������ں����ģ�ʲôҲû�С���������ϸ
�۲죬���ֶ�����һ�Դ����ĳ���(cao)��
LONG );
	set("exits", ([
		"out"  : __DIR__"tulu4",
	]));
	set("item_desc", ([
	    "cao" : "�����ܼ���ʵ�������ڸ�ס��ʲô����ʵ�ڿ��������\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1630);
	set("coor/y", -2210);
	set("coor/z", 10);
	setup();
}
void init()
{
	add_action("do_use", "use");
	add_action("do_zuan", "zuan");
}

int do_use(string arg)
{
	object me = this_player();

	if( !arg || arg=="" ) return 0;
	if (!present("fire", me))  return 0;
	if( arg=="fire" )
	{
		write("���ȼ�˻��ۣ����ֲݺ�������и������ƺ�������(zuan)��ȥ��\n");
		me->set_temp("marks/dashandong", 1);
		return 1;
	}
}

int do_zuan(string arg)
{
	object me = this_player();

	if (me->query_temp("marks/dashandong") ) {
		message("vision", me->name() + "���ݴ�������һ��Ͳ����ˡ�\n", environment(me), ({me}) );
		me->move(__DIR__"shandong");
		message("vision", me->name() + "�Ӳݴ������˹�����\n", environment(me), ({me}) );
		me->delete_temp("marks/dashandong");
		return 1;
	}
        else {
		write("�������Ķ��ꣿ��\n");
		return 1;
        }
}