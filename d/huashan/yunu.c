// yunu.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "��Ů��");
	set("long", @LONG
�����ǻ�ɽ���з壬��Ů�塣��˵����ʱ��ʿ��ʷ�ƴ��������
���������¹�Ů��Ū��İ�Ľ�������˹�͢�������ʷ�������ӣ���
����Ů�塣���������Ϊƽ�������������ķ���վ��������Ϻպ�����
�Ļ�ɽ���ɾ��ڴ˴�����������СС������Ǿ�����Ů���ˡ�����ϡ
ϡ������ʮ���䷿�ӣ��ǻ�ɽ�ɵĵط��������ο���ñ�������ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"west"      : __DIR__"yunuci",
		"north"     : __DIR__"square",
		"westdown"  : __DIR__"zhenyue",
		"southdown" : __DIR__"yunupath1",
		"northeast" : __DIR__"xiaolu1",
	]));
	set("objects", ([
		__DIR__"npc/yue-lingshan" : 1,
	]));

	set("outdoors", "huashan" );
	set("coor/x", -860);
	set("coor/y", 190);
	set("coor/z", 120);
	setup();
}
 