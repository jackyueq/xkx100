//room: neitang.c
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����һ�����µ����ã����ü򵥶����š�����վ�Ÿ�һ���̵�Ů
�ɣ���������Ц��Ц���ƺ��ǽ���������������һ��С���ˡ�
LONG );
	set("exits",([
		"north" : __DIR__"qinyun",
	]));
	set("objects",([
		CLASS_D("murong")+"/abi" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 810);
	set("coor/y", -1510);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}