// Last Modified by winder on May. 29 2001
// nwuji1.c

inherit ITEM;

string* titles = ({
	"�������ַ�",
	"ɢ���Ʒ�",
	"����ǧҶ���ַ�",
	"����ȭ��",
	"�޺�ȭ��",
	"�����Ʒ�",
	"Τ���Ʒ�",
});

string* skills = ({
	"fengyun-hand",
	"sanhua-strike",
	"qianye-hand",
	"jingang-cuff",
	"luohan-cuff",
	"boruo-strike",
	"weituo-strike",
});

void create()
{
	int i = random(sizeof(titles));

	set_name(titles[i], ({ "shaolin wuji", "wuji" }));
	set_weight(200);
	set("unit", "��");
	set("long", "����һ��" + titles[i] + "\n");
	set("value", 500);
	set("material", "paper");
	set("skill", ([
		"name":	skills[i],
		"exp_required":	10000,
		"jing_cost": 15+random(30),
		"difficulty":	25,
		"max_skill":	99
	]) );
}
