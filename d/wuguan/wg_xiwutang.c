// wg_xiwutang.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ϰ����");
	set("long", @LONG
���������רΪ�������������������ġ����ڽ�����ʦ��ʮ��Ϊ��
���ݵģ�����������������ڴ�ѧϰһЩ�����ķ����书��һ�������
����ȣ�����Ҳ��Ϊ���ѡ��һ����Ľ�����ɡ�
    ǽ�����Ÿ�����(tiezi)��
LONG );
	set("item_desc", ([
		"tiezi" : @TEXT
������ݾ����ߣ���������еĻ����书ѧȫ����Ҫ�Ļ����书�ǣ�

�� �����ڹ�
�� �����Ṧ
�� �����м�
�� ����ȭ�ţ�����ȭ�š������ַ��������Ʒ�������ָ��������ȭ����
             ����צ���������ȷ���ѡ���֡�
�� ������������������������ǹ����������������������������������
             �����ȷ������������������̷�����������������������
             �����޷�������������ѡ���֡�

����������������������������������������������������������
��������ݡ������ڻ����书
����������������������������������������������������������
  ���������ڹ� (force)            ����������ǹ�� (spear)
  ���������Ṧ (dodge)            �������������� (sword)
  ���������м� (parry)            �������������� (club)
  ��������ȭ�� (unarmed)          �������������� (stick)
  ���������ַ� (hand)             �����������ȷ� (staff)
  ���������Ʒ� (strike)           �������������� (axe)
  ��������ָ�� (finger)           �����������̷� (dagger)
  ��������ȭ�� (cuff)             �������������� (hammer)
  ��������צ�� (claw)             �������������� (hook)
�����������ȷ� (leg)              �����������޷� (whip)
�������������� (blade)            �������������� (throwing)
����������������������������������������������������������
��������ݡ������ڽ����书
����������������������������������������������������������
  ����̫�泤ȭ (changquan)          ��������ɢ�� (sanshou)

ѧϰ������: xue ʦ���� �书���� ����
TEXT
	]) );
	set("exits", ([
		"west" : __DIR__"wg_shilu-2",
	]));
	set("objects", ([
		__DIR__"npc/wg_jiaotou1" : 1,
	]));
	set("no_fight",1);
	set("coor/x", 51);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
/*

	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("axe", 80);
	set_skill("blade", 80);
	set_skill("claw", 80);
	set_skill("club", 80);
	set_skill("cuff", 80);
	set_skill("dagger", 80);
	set_skill("finger", 80);
	set_skill("hammer", 80);
	set_skill("hand", 80);
	set_skill("hook", 80);
	set_skill("leg", 80);
	set_skill("spear", 80);
	set_skill("staff", 80);
	set_skill("stick", 80);
	set_skill("strike", 80);
	set_skill("sword", 80);
	set_skill("throwing", 80);
	set_skill("unarmed", 80);
	set_skill("whip", 80);
	*/
