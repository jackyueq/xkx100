//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���Ǿ��ݱ����š���ǽ��Ȼ�����Ƶģ�ȴҲ��ΰ׳�ۡ�����������
�ߣ��������ֵľ��������ˡ�������һ������·��
LONG );
	set("exits", ([
		"south" : __DIR__"xijie1",
		"north" : __DIR__"tulu",
	]));
	set("objects", ([
		"/d/huashan/npc/haoke" : 1,
		"/d/taishan/npc/dao-ke" : 2,
	]));
	set("outdoors", "jiangling");
	set("coor/x", -1500);
	set("coor/y", -1100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}