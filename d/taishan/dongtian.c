// Room: /d/taishan/dongtian.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�չ۷嶫��Ϊ�����ţ�˫ʯ���ţ���᷶��Ķ�����ڡ�����Ϊ����
�ţ�Ͽ�ڶ��ա���Ϊӥ���ˮ����������ϴ���塣���������¹Ŷ���
�������徲ʯ�ݣ�Ԫ��Ů�������徲���ڴ����档�˴�����Ƨ��������
�������׺����˳����䱱Ϊ����ɽ����Ѩͨ������ʱ�չ⴩�ա� 
LONG );
	set("exits", ([
		"west" : __DIR__"riguanroad2",
	]));
	set("objects", ([
		CLASS_D("taishan")+"/yuyinzi" : 1,
	]));
	set("outdoors", "taishan");
	set("coor/x", 410);
	set("coor/y", 770);
	set("coor/z", 190);
	setup();
	replace_program(ROOM);
}
