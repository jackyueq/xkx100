//Edited by fandog, 02/16/2000

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���Ǿ��ݳ�����һ���ϱ�����Ĵ�֡��ƺ��в�������������ȥ��
�ҡ�������һ�����̣�����˽����������������ӡ�������֪�����š�
LONG
	);
	set("outdoors", "jiangling");
	set("objects", ([
		"/d/huashan/npc/haoke"  : 2,
		"/d/taishan/npc/jian-ke": 1,
		"/d/taishan/npc/dao-ke" : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"yamen",
		"south" : __DIR__"xijie4",
		"west"  : __DIR__"shupu",
		"north" : __DIR__"xijie2",
	]));

	set("coor/x", -1500);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}