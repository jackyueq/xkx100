// Room: /d/baituo/bridge.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ��С���ţ�������ɽ���ϵı�ѩ�ڻ��γ�һ���峺��СϪ��
�����»�����������ʱ����Ƥ��С��Ծ��ˮ�棬�������»���һ������
ɫ�Ļ��ߡ�
LONG	);
	set("outdoors", "baituo");
//	set("no_clean_up", 0);
	set("exits", ([
		"northwest" : __DIR__"guangchang",
		"east"      : __DIR__"xijie",
	]));
	set("objects",([
		__DIR__"npc/cungu" : 1,
	]));
	set("coor/x", -50000);
	set("coor/y", 19980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
