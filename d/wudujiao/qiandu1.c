// Room: /d/wudujiao/qiandu1.c

inherit ROOM;

void create()
{
        set("short", "ǧ������");
        set("long", @LONG
�������嶾����������ĵط���ɽ������һ����Ȼ��ʯ������
�������Ŀ��������һ��ɽ�紵�������ŵ�һ����ζ������վ��
�����嶾�̵��ӡ�
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "south" : __DIR__"wdsl4",
                "north" : __DIR__"qiandu2",
        ]));
        set("objects", ([
                __DIR__"npc/dizi": 4,
        ]));

        set("coor/x", -44960);
	set("coor/y", -81030);
	set("coor/z", 20);
	setup();
}
int valid_leave(object me, string dir)
{
    int i;
    object ob;
    me=this_player();
    if(dir=="north")
    {
    if ((string)me->query("family/family_name")!="�嶾��"
        & objectp(present("di zi", environment(me))))
          return notify_fail("�嶾�̵��Ӻ�Ȼ��ס�㣬�����ȵ�����λ" +
           RANK_D->query_respect(me) + "��ͷ���Ե����ʲô��\n");
    }
    return ::valid_leave(me, dir);
}

