// Room: /d/qilian/zibaipo.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "�ϰ���");
	set("long", @LONG
�ϰ���������ɽ��������Сɽ�壬���羰���ѡ���ɽСϪ��������
ɽ���������С���ɽʢ��һ����ɫɽ�����ļ���л���ഫ�����ϵ�����
���֣����Զﴫ������ϰأ���ʵɽ��һ�Ű���Ҳû�С�
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"east"      : __DIR__"tieshishan",
		"westup"    : __DIR__"qitianfeng",
		"northeast" : __DIR__"ailaoshan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -14000);
	set("coor/y", 3000);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}