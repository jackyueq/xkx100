// Feb. 6, 1999 by Winder
inherit ROOM;
int do_use(string arg);
int do_zuan(string arg);
void create()
{
        set("short", "ɽ����ͷ");
	set("long", @LONG
�������������ȥ������Խ���غ����������ֲ�����ָ����
������������߲�ͣ�ع�Ц��������ë���Ȼ����ãȻ��֪����
���Ǻá������Ѿ�ɽ����ͷ�ˣ���·���ߡ�
LONG
	);
	set("exits", ([
                "north" : __DIR__"shandong6",
	]));
	set("coor/x", 1600);
	set("coor/y", -1970);
	set("coor/z", 20);
	setup();
}
void init()
{
        add_action("do_use", "use");
        add_action("do_zuan", "zuan");
}
int do_use(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write(
             "���ȼ�˻��ۣ�����ɽ���ұ���һ���ѷ죬�ƺ�������(zuan)��ȥ��\n"
             );
             this_player()->set_temp("marks/��1", 1);
             return 1;
       }
}
int do_zuan(string arg)
{
        object me;
        me = this_player();
        if (me->query_temp("marks/��1") ) {
            message("vision", me->name() + "ͻȻһ�Ųȿգ�����ֱ����׹��\n",
                    environment(me), ({me}) );
            me->move(__DIR__"midao");
            me->unconcious();
            message("vision", me->name() + "��ɽ�������������\n",
                    environment(me), ({me}) );
            this_player()->delete_temp("marks/��1");
            return 1;
        }
        else {
            write("�������Ķ���?!\n");
            return 1;
        }
}