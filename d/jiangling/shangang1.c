//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һƬ��ʯ���ӣ��Ӳݴ�����������֡�ɽ�Ը���û�˼ң��뿪
��·��Զ��Ҳû�˾�����ɽ������һ��СС��Բ������������һ��ʯ
��(bei)��
LONG );
	set("exits", ([
		"west"  : __DIR__"shandao5",
	]));
	set("item_desc", ([
		"bei" : "��Ů��˪��֮Ĺ\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "jiangling");
	set("coor/x", -1460);
	set("coor/y", -2050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}