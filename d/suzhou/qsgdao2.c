// Room: /d/suzhou/qsgdao2.c
// Last Modified by Winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long",@long
������һ����ʯ����ϣ����������ǳ���æ����ʱ�������������
�Ҷ��������������һЩС��̯���ƺ���һ�����С�����ͨ�����ݳǡ�
long);
	set("outdoors", "suzhou");                        
	set("objects",([
		__DIR__"npc/yetu" : 2,
	]));
	set("exits",([
		"north" : __DIR__"nanmen",
		"south" : __DIR__"qsgdao1",
	]));
	set("coor/x", 850);
	set("coor/y", -1060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
