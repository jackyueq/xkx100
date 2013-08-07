// Room: /d/quanzhou/portroad4.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�ۿ�·");
	set("long", @LONG
�����ô�黨��ʯ�̳ɵĿ������ƽ̹��ʵ��·���������ų�
�صĻ�������������������Ӷ�����ʦ�������������Ǽ�ֵ���ƵĻ��
�ϱ��ǰ����ۣ������Ǵ��룬���ϱ����������ۡ�
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"east"      : __DIR__"chuanwu",
		"south"     : __DIR__"anhaigang",
		"northwest" : __DIR__"portroad3",
		"southeast" : __DIR__"yongninggang",
	]));
	set("objects", ([
		"/d/taishan/npc/tangzi" : 1,
		__DIR__"npc/kuli" : 2,
	]));
	set("coor/x", 1860);
	set("coor/y", -6620);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
