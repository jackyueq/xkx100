// room: /d/xingxiu/saimachang.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������С����������������ھ���ά�����ġ�����׷�����ݡ�
һ��С���ӿ�����һ�����ﲢ�����۵�һ���۷��㡣ȥ��·��С���ӿ�
�ԶԹ����������������ʱ����������ñ��ӳ��С���ӡ���Ȼ�����
����ϲ�����С���ӣ���޾ͻ���Щ������Ļ�����С���Ӻ��ܵġ�
LONG );
	set("exits", ([ 
		"southeast" : __DIR__"yili",
	]));
//	set("no_clean_up", 0);
	set("outdoors", "xiyu");
	set("objects", ([
		__DIR__"npc/alamuhan" : 1,
	]) );
	set("coor/x", -39100);
	set("coor/y", 13100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
