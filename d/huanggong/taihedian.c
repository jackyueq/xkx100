// Room: /d/huanggong/taihedian.c
inherit ROOM;

void create()
{
	set("short", "̫�͵�");
	set("long", @LONG
����ǽ��Ǳ���. ������, �ʻ涰��, �����߶�, ������֮��, 
���ǲ��ûԻ�. ������е��οվ����ֽ�����, ����˵Ҳ֪�����Ǿ���
����. ������Χ���������۽���������, ����ǰ���������۵��ɺ׺�
¯��. �����Ǿ���ϸ�̵�Χ��. ÿ�ջ��ڴ��ϳ�����, ��������. ��˵
�����ξ��ڴ������, �㾡��������.
LONG
	);
	set("exits", ([
		"north"     : __DIR__"zhonghedian",
		"south"     : __DIR__"taiji",
		"east"      : __DIR__"yongxiang3",
		"west"      : __DIR__"yongxiang2",
	]));
	set("coor/x", -200);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}