// baishulin2.c ������
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���߽��˰����ֵ�������²��ź�����Ҷ��������������
�Ĺ��߷ǳ��������㼸��ʲô���������ˡ�ͻȻһֻ���������ǰ��
��֦���͵����˹�ȥ��������һ����
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup" : __DIR__"baishulin4",
                "west" : __DIR__"baishulin1",
        ]));
        set("objects", ([
                __DIR__"npc/yunbao" : 1,
        ]));
	set("coor/x", -3130);
	set("coor/y", 30);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}