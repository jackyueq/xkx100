// force-book.c

inherit ITEM;

string* titles = ({
		 "�������ؼ�",
});

void create()
{
		  set_name(titles[random(sizeof(titles))], ({ "shu", "book" }));
		  set_weight(200);
		  if( clonep() )
					 set_default_object(__FILE__);
		  else {
		  set("unit", "��");
		  set("long", "�����������ڹ��ķ����ؼ���\n");
		  set("value", 500);
		  set("material", "paper");
		  set("skill", ([
		  "name": "force",     // name of the skill
		  "exp_required": 1000,      // minimum combat experience required
		  "jing_cost":    15,     // jing cost every time study this
		  "difficulty":   20,     // the base int to learn this skill
		  "max_skill":    41      // the maximum level you learn
					 ]) );
		  }
}
