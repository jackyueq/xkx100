// Room: /d/nanshaolin/cdian-2.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����������������������Ŵ�Ħ��ʦ��������ʿ�Ļ����Լ�
һЩ����Ԫ�ϵ��ֻ�������ɢ�ҵط���������ţ�ľ��ȡ������˴���
���ɵ��Ӵ�������֮������λ����ɮ���������붨���������ĵ�������
����
LONG);
	set("exits", ([
		"east" : __DIR__"gchang-2",
	]));
	set("objects",([
		WEAPON_DIR+"hammer/muchui" : 1,
	]));
	set("coor/x", 1800);
	set("coor/y", -6290);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

