//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "����");
	set ("long", @LONG
�������Ϊ��ף��ү����ʮ���ٲ��õĴ�����ǰ�����ٵĿ�����½
������������Ѿ��������æ�Ŷ˲���ˮ��������һ�����ο����������
�ں��ڱ���������
LONG);
	set("exits", ([
		"west"  : __DIR__"damen",
		"east"  : __DIR__"zoulang1",
		"south" : __DIR__"nanlou",
		"north" : __DIR__"beilou",
	]));
	set("objects", ([
		__DIR__"npc/wanzhenshan" : 1,
		__DIR__"npc/lvtong"      : 1,
		__DIR__"npc/lukun"       : 1,
		__DIR__"npc/zhouqi"      : 1,
	]));

	set("coor/x", -1489);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
