// /beijing/hangang.c
// Last modified by winder 2003.10.10

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������Ǵ�֮�����˻��Ĵ��Ž�ʯ����������������������һȺ
Ⱥ��Ÿ��ŷŷ..���ؽ��ţ���ʱ�����Ծ�����棬��������˻�����
�����Ҵ� (chuan)���������ż����������ˣ��˴��ɶɹ��󺣵�
�ﺣ����һ�ˡ���������Ǿ��Ǳ����ˣ�������һ���޼ʵĴ󺣡�
LONG );
	set("exits", ([
                "west" : __DIR__"road10",
	]));
	set("item_desc", ([
                "chuan" : "һ�Ҵ󷫴�����úܽ�ʵ���������Գ�Զ���ġ�\n",
	]));
	set("objects", ([
		__DIR__"npc/flowerg":2,
		"/d/shenlong/npc/chuanfu" : 1,
		"/d/shenlong/npc/xiucai" : 1,
	]));
	set("outdoors", "huabei");
	set("coor/x", 500);
	set("coor/y", 2000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
