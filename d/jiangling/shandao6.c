//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ���Է���ũ��̤������ɽ����ż���ɼ�һ�����������˱���
���������ŵ����߹���������һƬ������ɽ�֣��ϱ߾��������İ׵۳�
�ˡ�
LONG );
	set("exits", ([
		"south" : __DIR__"baidicheng",
		"north" : __DIR__"shennongjia",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1520);
	set("coor/y", -2050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}