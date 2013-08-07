// Room: /d/quanzhou/lingshan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ɽʥĹ");
	set("long", @LONG
����Ȫ�ݶ�����ɽ����´�������Ƹ��������䣬��˹���̴�ʼ��
�º�Ī������ͽ����ɳ���ʡ������������Ȫ�ݴ��̣������ڴˡ�Ĺ��
��һ��Բ��ʯ���ȣ�������һ���ı��ǣ��ˡ�֣�����㱮��(monument)��
������������������̫��֣�͵����������·��Ȫ�ݣ�������Ĺ���㵻
�棬�ٸ�Ϊ֮��ʯ���µı��̡�
LONG );
	set("outdoors", "quanzhou");
	set("item_desc", ([
		"monument" :
"���ղ��ܱ�̫��֣�ͣ�ǰ�������³Į˹�ȹ����ɡ�����
ʮ�����������㣬�����鱣�ӡ����ֺ��ռ�����\n",
	]));
	set("exits", ([
		"south" : __DIR__"portroad1",
		"west"  : __DIR__"tumenshuiguan",
		"east"  : __DIR__"luoyangqiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1880);
	set("coor/y", -6580);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
