// Room: /d/wudujiao/cun1.c

inherit ROOM;

void create()
{
        set("short", "С���");
        set("long", @LONG
�������һ����ߵ�һ��С�壬����м���ũ�ҵ�С�����ڴ���������
ˣ��ԶԶ���������ƴ��̣�æµ��һ������ǿ�ʼ�����ˡ�
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"cun2",
                "west" : __DIR__"jiang2",
        ]));
        set("objects", ([
                 __DIR__"npc/kid": 3,
        ]));

	set("coor/x", -44990);
	set("coor/y", -81010);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}