// juyan.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
һ·������ɽ·��Խ��Խ�ա�ֻ��һ�����ʯ����·�У��Կ�ƾ
�٣�����һ���ϸ��������ӣ�����״��ɭ�ɲ�������������η������
�ο��ڴ�פ��ۿ���������һƬï�ܵ����֡���������һ�����͵�ɽ
·��
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup"    : __DIR__"shanlu12",
                "southdown"  : __DIR__"shulin3",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/ji": 1,
        ]));

	set("coor/x", -3170);
	set("coor/y", 90);
	set("coor/z", 100);
	setup();
        replace_program(ROOM);
}
