// chengruiting.c

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����԰���߽������, ���Ͻ�ͤ, ������ǳ���ͤ. ͤ�ӳ��ϱ���, 
ͤ�����к���, �����о�. ����, ��ˮ�峺, ����Ϸ���ںɻ�֮��. ��
��, ��ˮ���, ������뾮����. 
LONG
);
	set("outdoors", "huanggong");
	set("exits", ([
		"southeast" : __DIR__"yuhuayuan",
	]) );
	set("no_clean_up", 0);
	set("coor/x", -210);
	set("coor/y", 5340);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}