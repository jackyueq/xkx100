// Room: /d/yueyang/taijiting.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "̫��ͤ");
	set("long", @LONG
̫��ͤΪ����׶��Сͤ��ͤ�ڵ�����������ϱ���̫��ͼ��������
���Ա�����ͥ��ɽ��ɫ��
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"dongtingmiao1",
	]));
	set("coor/x", -1670);
	set("coor/y", 2350);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
