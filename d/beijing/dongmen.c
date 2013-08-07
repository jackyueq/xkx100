// Room: /beijing/dongmen.c

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���Ƕ����ţ��������Ϸ����š����š��������֣���ǽ�����ż���
�ٸ���ʾ(gaoshi)��һ����ֱ����ʯ���������������졣�����ǽ�
�⣬Խ�����ſ��Կ�����������������������������ͨ�������
�����ǳ����š�
LONG );
	set("outdoors", "beijing");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east"  : __DIR__"road1",
		"west"  : __DIR__"dongcha2",
		"south" : __DIR__"matou",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -170);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return "������ػ�һ�ڷ���! \n�ٱ�һ�ˣ��ͽ�ʮ��;\n"
          "׽��һ�ˣ��ͽ������\n֪�鲻���ߣ���ն!\n���ݷ�\n";
}
