// Room: /d/wudujiao/wandu1.c

inherit ROOM;

void create()
{
        set("short", "�򶾿���");
        set("long", @LONG
�������嶾����������ĵط���ɽ������һ����Ȼ��ʯ������
�������Ŀ��������һ��ɽ�紵�������ŵ�һ����ζ����һ����
�����ڵĿ����ϸ������ڶ��ߴ��
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "south" : __DIR__"wandu2",
                "north" : __DIR__"wdsl3",
        ]));
        set("objects", ([
                  CLASS_D("wudujiao")+"/hehongyao": 1,
        ]));

        set("coor/x", -44970);
	set("coor/y", -81090);
	set("coor/z", 10);
	setup();
}
int valid_leave(object me, string dir)
{
        int i;
        object ob;
        me=this_player();
        if(dir=="south")
        {
            if( !present("tie shao", me)
                & objectp(present("he hongyao", environment(me))))
                return notify_fail("�κ�ҩ����һ�Σ���Ȼ��ס�㣬����˵������λ" + RANK_D->query_respect(me) + "û�н���׼�����ý��뱾��ʥ�ء�\n");
        }
        return ::valid_leave(me, dir);
}
