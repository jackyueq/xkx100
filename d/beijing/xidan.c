inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������������������ʮ�����֡�������Ȼ�࣬����ֻ�Ĵ�
���ƣ��Ŷ������������Ҳ��������ʲô�������м��ӻ��̣�ȥ������
�������˺ܶࡣ�������˴ӱ����������ƺ�����Ҳͦ���֡��ϱ�������
���֡�
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"zahuopu",
		"south" : __DIR__"xichang2",
		"north" : __DIR__"xidan1",
	]));
	set("objects", ([
		__DIR__"npc/xiaofan": 1,
		"/d/huashan/npc/youke": 2,
	]));
	set("coor/x", -220);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
