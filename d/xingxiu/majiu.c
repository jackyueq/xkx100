//Room: majiu1.c ���
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","���");
	set("long",@LONG
���Ǳ���С�����ǣ����깩Ӧ���ʲ��ϡ�����ش��Ὦ�������
�Ӷ��ÿͣ�������Զ�����������ֵܿ���������ǻ����ǣ����Ǻ���
�տ���������ι�����㣬�����������ˬˬ��һֱ�ź򵽿�����·����
�Ǿ�ľ���϶���һ����ľ��(paizi)��
    ����жѷ������Ѳ��ϣ�������һ����ۡ�
LONG);
	set("no_fight", "1");
	set("no_beg", "1");
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		"/d/city/npc/camel": 1,
		"/clone/misc/mafu": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ������:  rideca


TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"west" : __DIR__"kezhan",
//		"up"   : SHOP_DIR"yili_shop",
	]));
	set("no_clean_up", 0);
	set("coor/x", -38990);
	set("coor/y", 13100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
