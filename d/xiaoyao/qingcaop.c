// qingcaop.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
        set("short", "���ƺ");
        set("long", @LONG
�����������е�һƬ�Ƚϴ�Ŀյأ���Ի�����ƺ����Ϊ��������
֮����������ƽʱ���������������ǲ�֪��Ϊʲô������ȴ�������˼�
���֡��㿴����һ�����ˡ�
LONG );
	set("exits", ([
		"north" : __DIR__"xiaodao3",
		"south" : __DIR__"xiaodao5",
		"east" : __DIR__"xiaodao4",
		"west" : __DIR__"xiaodao1",
	]));
	set("outdoors", "xiaoyao");
	set("objects", ([
		CLASS_D("xiaoyao")+"/suxinghe": 1,
//		__DIR__"npc/xue": 1,
	]));
	set("valid_startroom", 1);
//	set("no_clean_up", 0);
	set("coor/x", 80);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
	"/clone/board/xiaoyao_b"->foo();
}