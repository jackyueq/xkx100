// Room: /d/lingzhou/qingong.c

inherit ROOM;

void create()
{
	set("short", "�޹�");
	set("long", @LONG
����������Ļʵ۵��޹���һɫ�İ���ذ壬��ɫ��ɴ�ʣ�������
�ʵ۵���齣�齱���һ�Ű��ϻ�Ƥ����̤��, ǽ�Ϲ��Ű������䵶����
˵����ެ�Ĺ�Ʒ����������������ֵҹ�ظ���ƫ�����ǽ���з���ӥ
�˳�ľ޻���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"piandian2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -17990);
	set("coor/y", 32110);
	set("coor/z", 0);

	setup();
	replace_program(ROOM);
}
