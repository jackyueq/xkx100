//Edited by fandog, 02/15/2000
inherit ROOM;
void create()
{
    set("short", "��Ĺ");
    set("long",@LONG
������ɭɭ�����Ǹ��Ŵ���Ĺ�ң�һ�����紵�����㲻�ɵô��˸�
���䡣��ǰ�����е�Ĺ�������������������Ƭ����ֽƬ�������и���
�����ľ�У�Ҳ��֪����װ����ô�Źֶ�����
LONG);
	set("exits", ([
		"up" : __DIR__"shangang2",
	]));
	set("objects", ([
		__DIR__"obj/muhe"    : 1,
	]));
	set("coor/x", -1490);
	set("coor/y", -2050);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}