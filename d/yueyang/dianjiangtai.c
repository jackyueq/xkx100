// Room: /d/yueyang/dianjiangtai.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "�㽫̨");
	set("long", @LONG
����ʯ������ˮ��һ��ƽ̨����̨����������³���ڴ˵������
�ġ��㽫̨�����㽫̨�ϲ಻Զ��һϵ�����Ĵ����ϣ�����˶�������
�����Ͼ�˵�����������õġ�
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"shijie7",
	]));
	set("coor/x", -1440);
	set("coor/y", -2280);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
