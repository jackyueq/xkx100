// Room: /d/qilian/qilianshan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
����ɽΪ������ɽ������߷壬������ǧ���ٶ��ף�ɽ��ͦ�Σ�Ϊ
�������Ȫ�����������˵ĵ�һɽ��ɽҰ������ʯ��Ϊ����һ����ۣ�
�붫�Ϸ�����ɽң�ԡ�ɽ�о���ʱ�����˾�ʯ����.
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"southeast" : __DIR__"niaojutai",
		"east"      : __DIR__"mazongshan",
		"west"      : __DIR__"tieshishan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -12000);
	set("coor/y", 3000);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}