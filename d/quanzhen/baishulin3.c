// baishulin3.c ������
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
                "northup" : __DIR__"cuipingfeng",
                "east" : __DIR__"baishulin4",
                "southdown" : __DIR__"baishulin1",
        ]));
        set("objects", ([
		"/clone/medicine/vegetable/sanqi" : random(2),
        ]));
	set("coor/x", -3140);
	set("coor/y", 40);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}