// Room: /yangzhou/pingtai5.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","ƽ̨");
	set("long",@LONG
����̨ǰƽ̨����ˮ���㣬��ʯΪ����Χ�Ե������������ա����
Ծ���ݿɷ��족�ķ�ò����ͨ����ͤ�����ʮ�ָ�¥̨ͤ��֮�䣬
���ú�ʯ��̨����ֲ���������ô����󡱵Ĺ�������ĵ�������Ե�ׯ
�ظ�����¶̨�����ʫ��һ��������ɽ����ˮ�������ﾡ���ϲ�δ��
��ʮ��������ҹ�����˺δ��̴����
LONG );
	set("outdoors", "shouxihu");
	set("objects", ([
		"/d/village/npc/kid" : 1,
	]));
	set("exits", ([
		"north"  : __DIR__"shizige",
		"south"  : __DIR__"chongyanting",
		"westup" : __DIR__"xichuntai",
		"east"   : __DIR__"ershisiqiao",
	]));
	set("coor/x", -50);
	set("coor/y", 100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}