// Room: /d/petroom.c
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��ʱһ������̡��߸ߵĹ�̨������һ����ͷ����ͷ�������һ��
�ŵ����ӣ��廨���ŵ����˲��ٶ�������̨�ϰ��ŵ����� (paizi)�г�
�˳������࣬����Ҫ�͹���(goumai)һֻ�ɡ���ͷ���������ֳ������
�ϳ������򶼳ɡ����������˲����棬�뻻���֣�Ҳ���԰Ѿɵĳ�
�ﷵ��(return)����ͷ��Ȼ������һֻ�µġ�
LONG );
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : HIR"
                                 ���ݳ����"HIC"

   ����"HIM"����"HIC"��"HIM"����"HIC"��������"HIM"��Ŀ"HIC"���������ש�"HIM"����"HIC"��"HIM"����"HIC"��������"HIM"��Ŀ"HIC"����������"HIC"
   ��  "HIG"��   dragon     "HIY"��ʮ�����ƽ�"HIC"  ��  "HIG"��� phenix     "HIY"��ʮ�����ƽ�"HIC"  ��
   ��  "HIG"���� kylin      "HIY"��ʮ�����ƽ�"HIC"  ��  "HIG"��   elephant   "HIY"��ʮ�����ƽ�"HIC"  ��
   ��  "HIG"ʨ   lion       "HIY"��ʮ�����ƽ�"HIC"  ��  "HIG"��   tiger      "HIY"��ʮ�����ƽ�"HIC"  ��
   ��  "HIG"��   panther    "HIY"��ʮ�����ƽ�"HIC"  ��  "HIG"��   vulture    "HIY"��ʮ�����ƽ�"HIC"  ��
   ��  "HIG"��   bear       "HIY"��ʮ�����ƽ�"HIC"  ��  "HIG"��   fox        "HIY"��ʮ�����ƽ�"HIC"  ��
   ��  "HIG"��   wolf       "HIY"��ʮ�����ƽ�"HIC"  ��  "HIG"��   dog        "HIY"��ʮ�����ƽ�"HIC"  ��
   ��  "HIG"��   pig        "HIY"��ʮ�����ƽ�"HIC"  ��  "HIG"��   crocodile  "HIY"��ʮ�����ƽ�"HIC"  ��
   ��  "HIG"��   horse      "HIY"��ʮ�����ƽ�"HIC"  ��  "HIG"¿   donkey     "HIY"��ʮ�����ƽ�"HIC"  ��
   ��  "HIG"ţ   cattle     "HIY"��ʮ�����ƽ�"HIC"  ��  "HIG"��   monkey     "HIY"��ʮ�����ƽ�"HIC"  ��
   ��  "HIG"ӥ   eagle      "HIY"��ʮ�����ƽ�"HIC"  ��  "HIG"¹   deer       "HIY"��ʮ�����ƽ�"HIC"  ��
   ��  "HIG"��   snake      "HIY"ʮ�����ƽ�"HIC"    ��  "HIG"��   marten     "HIY"ʮ�����ƽ�"HIC"    ��
   ��  "HIG"è   cat        "HIY"�����ƽ�"HIC"      ��  "HIG"��   mouse      "HIY"�����ƽ�"HIC"      ��
   ��  "HIG"��   rabbit     "HIY"�����ƽ�"HIC"      ��  "HIG"��   tortise    "HIY"�����ƽ�"HIC"      ��
   ��  "HIG"��   chicken    "HIY"�����ƽ�"HIC"      ��  "HIG"Ѽ   duck       "HIY"�����ƽ�"HIC"      ��
   �����������������������������������ߩ���������������������������������"HIB"
        goumai������    return������    zancun���ݴ�    lingqu����ȡ
\n"NOR,
	]));
	set("exits", ([
		"northeast" : __DIR__"caohebeijie",
	]));
	set("objects", ([
		__DIR__"npc/oldman" : 1,
	]));
	set("coor/x", -30);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
