//ROOM: /d/yanziwu/jiashan.c

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long",@LONG
��ʯ�ѵ�����ʯ�β����Щͷ��Ŀѣ����ô��ɽ���㲻֪������
һ��������ɽ�����谵���ۣ�ʵ�ڲ�֪ͨ��ʲô�ط���
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"west" : __DIR__"zuijing",
		"east" : __DIR__"shuiyun",
		"north": __DIR__"huayuan",
//		"south": __DIR__"huanshi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 840);
	set("coor/y", -1540);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}