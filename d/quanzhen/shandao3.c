// shandao3.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�˶�ɽ·��ͨ����ɽ�š���������һ��Ƭ���֡������¿�������
һ���ϴ�ĺ���
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southup"   : __DIR__"shulin6",
                "northdown" : __DIR__"taiyi1",
        ]));
        set("objects", ([
                "/clone/medicine/vegetable/lingzhi" : random(2),
        ]));
	set("coor/x", -3190);
	set("coor/y", 170);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}
