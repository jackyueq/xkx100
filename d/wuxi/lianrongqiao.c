// Room: /d/wuxi/lianrongqiao.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������׳Ʊ��Ŵ��ţ���Ϊ��һ���ٵ��������޵úܿ��ƽ̹����
���������ƥ���ж������������ڹٱ����ʽϽ�����׼С��С������
Ӫ������������Ҳ��̫�ࡣ�����Ե�ʮ�ָɾ���Ҳ�����壬����ȥ�ǳ�
����ǳ����ߡ�
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"north" : __DIR__"road5",
		"south" : __DIR__"northgate",
	]));
	set("no_clean_up", 0);
	set("coor/x", 370);
	set("coor/y", -750);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}