// Room: /d/wuxi/northroad1.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
һ�����͵Ľ��Ͻֵ���������Ȼ����С��ש�̳ɣ���Ҳ��ʮ�ֵ�ƽ
�������ߵĵ��̷����ߵ����޲�͸��ˮ�������������ϲ�����ǻ����
��������ɫ�Ҵң��ϱ߾��������ǵ����Ĺ㳡�������ǽ�����ɲ�簲�£�
���Ը��ص����ǽ������������ʮ����ʢ��������һ��ר��������ɽ��
�˵ĵ��̣��������������ÿ����˵ĵط���
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"north" : __DIR__"jinlianqiao",
		"south" : __DIR__"guangchang",
		"east"  : __DIR__"chongansi",
		"west"  : __DIR__"nirenpu",
	]));
	set("objects", ([
			__DIR__"npc/lady" : 1,
	]));
	set("coor/x", 370);
	set("coor/y", -790);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}